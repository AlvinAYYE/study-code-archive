<?php
function check($number)
{
    if ($number <= 3) return true;
    if ($number % 2 == 0 || $number % 3 == 0) return false;
    for ($i = 5; $i * $i <= $number; $i += 6) {
        if ($number % $i == 0 || $number % ($i + 2) == 0) return false;
    }
    return true;
}
while (($line = readline()) !== false) {
    $number = (int)$line;
    if (check($number))echo "Y\n";
    else echo "N\n";
}