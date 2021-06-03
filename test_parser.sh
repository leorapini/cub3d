#!/bin/sh

echo "\n/////////////// TEST PARSER ////////////////"

echo "\n++++++++++++++ TEST R VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting r_wrong_format.cub"
./cub3d ./tests/parser/r_wrong_format.cub

echo "\nTesting r_wrong_format2.cub"
./cub3d ./tests/parser/r_wrong_format.cub

echo "\nTesting r_empty_value.cub"
./cub3d ./tests/parser/r_empty_value.cub

echo "\nTesting r_no_r.cub"
./cub3d ./tests/parser/r_no_r.cub
echo ""

echo "\n++++++++++++++ TEST NO VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting no_empty_value.cub"
./cub3d ./tests/parser/no_empty_value.cub

echo "\nTesting no_no_no.cub"
./cub3d ./tests/parser/no_no_no.cub

echo "\nTesting no_file_not_found.cub"
./cub3d ./tests/parser/no_file_not_found.cub

echo "\nTesting no_file_not_found_2.cub"
./cub3d ./tests/parser/no_file_not_found_2.cub
echo ""
