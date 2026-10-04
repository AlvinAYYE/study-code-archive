<?php
while (($line = readline()) !== false) {
    $number = strlen($line);
    $allBra = 0;
    $bracket = 0;
    $bra = 0;
    for ($i = 0; $i < $number; $i++) {
        if ($line[$i] == "(") {
            $bra++;
        } else {
            if ($bra > 0) {
                $bracket += 2;
                $bra--;
            }
        }
    }
    $allBra -= $bra;
    echo $bracket . "\n";
}