/*
 * ==========================================================================
 * UVa 10044 - Erdos Numbers
 * Title-CN: 艾狄胥數
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, string
 * ==========================================================================
 * [EN] Problem: Compute Erdos numbers (shortest collaboration distance from Paul Erdos).
 * [中文] 題目說明: 建立作者合作無向圖，計算由 Erdos 起算的 BFS 最短距離。
 * [EN] Approach: Graph construction from paper author lists + BFS from Erdos.
 * [中文] 思路: 論文作者建立圖節點與邊，從 Erdos 跑 BFS 標記距離。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_BUCKETS 65537
#define LINE_SIZE 65536

typedef struct {
    char *name;
    int *neighbors;
    int neighbor_count;
    int neighbor_capacity;
    int hash_next;
} Author;

typedef struct {
    Author *authors;
    int count;
    int capacity;
    int buckets[HASH_BUCKETS];
} CollaborationGraph;

static uint32_t hash_name(const char *name) {
    uint32_t hash = 2166136261U;

    while (*name != '\0') {
        hash ^= (unsigned char)*name++;
        hash *= 16777619U;
    }
    return hash;
}

static char *copy_string(const char *text) {
    size_t length = strlen(text) + 1;
    char *copy = malloc(length);

    if (copy != NULL) {
        memcpy(copy, text, length);
    }
    return copy;
}

static void graph_init(CollaborationGraph *graph) {
    graph->authors = NULL;
    graph->count = 0;
    graph->capacity = 0;
    for (int i = 0; i < HASH_BUCKETS; ++i) {
        graph->buckets[i] = -1;
    }
}

static int graph_find(const CollaborationGraph *graph, const char *name) {
    unsigned int bucket = hash_name(name) % HASH_BUCKETS;

    for (int index = graph->buckets[bucket]; index >= 0;
         index = graph->authors[index].hash_next) {
        if (strcmp(graph->authors[index].name, name) == 0) {
            return index;
        }
    }
    return -1;
}

static int graph_get_or_add(CollaborationGraph *graph, const char *name) {
    int existing = graph_find(graph, name);
    unsigned int bucket;
    Author *author;

    if (existing >= 0) {
        return existing;
    }
    if (graph->count == graph->capacity) {
        int new_capacity = graph->capacity == 0 ? 128 : graph->capacity * 2;
        Author *resized = realloc(graph->authors,
                                  (size_t)new_capacity * sizeof(*resized));
        if (resized == NULL) {
            return -1;
        }
        graph->authors = resized;
        graph->capacity = new_capacity;
    }

    existing = graph->count++;
    author = &graph->authors[existing];
    author->name = copy_string(name);
    author->neighbors = NULL;
    author->neighbor_count = 0;
    author->neighbor_capacity = 0;
    bucket = hash_name(name) % HASH_BUCKETS;
    author->hash_next = graph->buckets[bucket];
    graph->buckets[bucket] = existing;
    return existing;
}

static void add_neighbor(Author *author, int neighbor) {
    if (author->neighbor_count == author->neighbor_capacity) {
        int new_capacity = author->neighbor_capacity == 0
                               ? 8
                               : author->neighbor_capacity * 2;
        int *resized = realloc(author->neighbors,
                               (size_t)new_capacity * sizeof(*resized));
        if (resized == NULL) {
            return;
        }
        author->neighbors = resized;
        author->neighbor_capacity = new_capacity;
    }
    author->neighbors[author->neighbor_count++] = neighbor;
}

static void graph_add_edge(CollaborationGraph *graph, int left, int right) {
    add_neighbor(&graph->authors[left], right);
    add_neighbor(&graph->authors[right], left);
}

static void graph_free(CollaborationGraph *graph) {
    for (int i = 0; i < graph->count; ++i) {
        free(graph->authors[i].name);
        free(graph->authors[i].neighbors);
    }
    free(graph->authors);
}

static void parse_paper(CollaborationGraph *graph, char *line) {
    char *colon = strchr(line, ':');
    char *cursor = line;
    int *paper_authors = NULL;
    int author_count = 0;
    int author_capacity = 0;

    if (colon == NULL) {
        return;
    }

    while (cursor < colon) {
        char *surname_comma;
        char *separator;
        char *start;
        char *end;
        char name[512];
        size_t name_length;
        int id;

        while (cursor < colon && *cursor == ' ') {
            ++cursor;
        }
        surname_comma = memchr(cursor, ',', (size_t)(colon - cursor));
        if (surname_comma == NULL) {
            break;
        }
        separator = memchr(surname_comma + 1, ',',
                           (size_t)(colon - surname_comma - 1));
        start = cursor;
        end = separator == NULL ? colon : separator;
        while (end > start && end[-1] == ' ') {
            --end;
        }
        name_length = (size_t)(end - start);
        if (name_length >= sizeof(name)) {
            name_length = sizeof(name) - 1;
        }
        memcpy(name, start, name_length);
        name[name_length] = '\0';
        id = graph_get_or_add(graph, name);

        if (id >= 0) {
            if (author_count == author_capacity) {
                int new_capacity = author_capacity == 0 ? 8 : author_capacity * 2;
                int *resized = realloc(paper_authors,
                                       (size_t)new_capacity * sizeof(*resized));
                if (resized == NULL) {
                    free(paper_authors);
                    return;
                }
                paper_authors = resized;
                author_capacity = new_capacity;
            }
            paper_authors[author_count++] = id;
        }

        if (separator == NULL) {
            break;
        }
        cursor = separator + 1;
    }

    for (int i = 0; i < author_count; ++i) {
        for (int j = i + 1; j < author_count; ++j) {
            graph_add_edge(graph, paper_authors[i], paper_authors[j]);
        }
    }
    free(paper_authors);
}

static int *erdos_distances(const CollaborationGraph *graph) {
    int *distance = malloc((size_t)graph->count * sizeof(*distance));
    int *queue = malloc((size_t)graph->count * sizeof(*queue));
    int root = graph_find(graph, "Erdos, P.");
    int head = 0;
    int tail = 0;

    if (distance == NULL || queue == NULL) {
        free(distance);
        free(queue);
        return NULL;
    }
    for (int i = 0; i < graph->count; ++i) {
        distance[i] = -1;
    }
    if (root >= 0) {
        distance[root] = 0;
        queue[tail++] = root;
    }

    while (head < tail) {
        int current = queue[head++];
        const Author *author = &graph->authors[current];

        for (int i = 0; i < author->neighbor_count; ++i) {
            int next = author->neighbors[i];

            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                queue[tail++] = next;
            }
        }
    }

    free(queue);
    return distance;
}

void solve_uva10044(FILE *input, FILE *output) {
    int scenarios;
    char *line = malloc(LINE_SIZE);

    if (line == NULL || fscanf(input, "%d", &scenarios) != 1) {
        free(line);
        return;
    }

    for (int scenario = 1; scenario <= scenarios; ++scenario) {
        int paper_count;
        int query_count;
        CollaborationGraph graph;
        int *distance;

        if (fscanf(input, "%d %d", &paper_count, &query_count) != 2) {
            break;
        }
        (void)fgets(line, LINE_SIZE, input);
        graph_init(&graph);
        for (int i = 0; i < paper_count; ++i) {
            if (fgets(line, LINE_SIZE, input) != NULL) {
                parse_paper(&graph, line);
            }
        }

        distance = erdos_distances(&graph);
        fprintf(output, "Scenario %d\n", scenario);
        for (int i = 0; i < query_count; ++i) {
            if (fgets(line, LINE_SIZE, input) != NULL) {
                int id;
                size_t length = strcspn(line, "\r\n");

                while (length > 0 && line[length - 1] == ' ') {
                    --length;
                }
                line[length] = '\0';
                id = graph_find(&graph, line);
                fprintf(output, "%s ", line);
                if (id >= 0 && distance != NULL && distance[id] >= 0) {
                    fprintf(output, "%d\n", distance[id]);
                } else {
                    fputs("infinity\n", output);
                }
            }
        }
        free(distance);
        graph_free(&graph);
    }
    free(line);
}

int main(void) {
    solve_uva10044(stdin, stdout);
    return 0;
}
