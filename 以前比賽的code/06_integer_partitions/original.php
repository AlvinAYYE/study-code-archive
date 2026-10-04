<?php
$num = readline();
function dfs($rem, $max, &$arr = [])
{
    if ($rem == 0) {
        echo implode(" ", $arr) . PHP_EOL;
        return;
    }
    for ($i = min($rem, $max); $i >= 1; $i--) {
        $arr[] = $i;
        dfs($rem - $i, $i, $arr);
        array_pop($arr);
    }
}
$arr = [];
dfs($num, $num, $arr);