<?php
while (($line = readline()) !== false) {
    $code = [
        'I' => 1,
        'V' => 5,
        'X' => 10,
        'L' => 50,
        'C' => 100,
        'D' => 500,
        'M' => 1000,
    ];
    $number = 0;
    for ($i = 0; $i < strlen($line); $i++) {
        if ($i + 1 < strlen($line) && $code[$line[$i]] < $code[$line[$i + 1]]) {
            $number -= $code[$line[$i]];
        }else{
            $number += $code[$line[$i]];
        }
    }
    echo "$number \n";
}