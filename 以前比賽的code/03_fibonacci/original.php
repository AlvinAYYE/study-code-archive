<?php
$arr = array_fill(0, 94, 0);
$arr[0] = 0;
$arr[1] = 1;
$arr[2] = 1;
for ($i = 3; $i < 94; $i++) {
    $arr[$i] = $arr[$i - 1] + $arr[$i - 2];
}
while (($line = readline()) !== false) {
    echo $arr[$line];
}