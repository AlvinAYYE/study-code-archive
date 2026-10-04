<?php
while (($line = readline()) !== false) {
    $c = [1, 5, 10, 50];
    $c = array_reverse($c);
    $e = [];
    $a = 0;
    for ($i = 0; $i < 4; $i++) {
        $e[$i] = 0;
        while ($c[$i] <= $line) {
            $a++;
            $e[$i]++;
            $line -= $c[$i];
        }
    }
    $c = array_reverse($c);
    $e = array_reverse($e);
    for ($i = 0; $i < 4; $i++) {
        echo "$c[$i] $e[$i]\n";
    }
    echo $a;
}