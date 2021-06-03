#!/bin/sh

echo "\n/////////////// TEST PARSER ////////////////"

echo "\n++++++++++++++ TEST R VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting r_wrong_format.cub"
./cub3d ./tests/parser/r_wrong_format.cub

echo "\nTesting r_wrong_format2.cub"
./cub3d ./tests/parser/r_wrong_format2.cub

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

echo "\n++++++++++++++ TEST SO VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting so_empty_value.cub"
./cub3d ./tests/parser/so_empty_value.cub

echo "\nTesting so_no_so.cub"
./cub3d ./tests/parser/so_no_so.cub

echo "\nTesting so_file_not_found.cub"
./cub3d ./tests/parser/so_file_not_found.cub

echo "\nTesting so_file_not_found_2.cub"
./cub3d ./tests/parser/so_file_not_found_2.cub
echo ""

echo "\n++++++++++++++ TEST WE VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting we_empty_value.cub"
./cub3d ./tests/parser/we_empty_value.cub

echo "\nTesting we_no_so.cub"
./cub3d ./tests/parser/we_no_we.cub

echo "\nTesting we_file_not_found.cub"
./cub3d ./tests/parser/we_file_not_found.cub

echo "\nTesting we_file_not_found_2.cub"
./cub3d ./tests/parser/we_file_not_found_2.cub
echo ""

echo "\n++++++++++++++ TEST EA VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting ea_empty_value.cub"
./cub3d ./tests/parser/ea_empty_value.cub

echo "\nTesting ea_no_ea.cub"
./cub3d ./tests/parser/ea_no_ea.cub

echo "\nTesting ea_file_not_found.cub"
./cub3d ./tests/parser/ea_file_not_found.cub

echo "\nTesting ea_file_not_found_2.cub"
./cub3d ./tests/parser/ea_file_not_found_2.cub
echo ""

echo "\n++++++++++++++ TEST S VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting spr_empty_value.cub"
./cub3d ./tests/parser/spr_empty_value.cub

echo "\nTesting spr_no_spr.cub"
./cub3d ./tests/parser/spr_no_spr.cub

echo "\nTesting spr_file_not_found.cub"
./cub3d ./tests/parser/spr_file_not_found.cub
echo ""

echo "\n++++++++++++++ TEST F VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting f_wrong_format.cub"
./cub3d ./tests/parser/f_wrong_format.cub

echo "\nTesting f_wrong_format_2.cub"
./cub3d ./tests/parser/f_wrong_format_2.cub

echo "\nTesting f_wrong_format_3.cub"
./cub3d ./tests/parser/f_wrong_format_3.cub

echo "\nTesting f_empty_value.cub"
./cub3d ./tests/parser/f_empty_value.cub

echo "\nTesting f_no_f.cub"
./cub3d ./tests/parser/f_no_f.cub
echo ""

echo "\n++++++++++++++ TEST C VALUES +++++++++++++++"
echo "Testing success.cub"
./cub3d ./tests/parser/success.cub

echo "\nTesting c_wrong_format.cub"
./cub3d ./tests/parser/c_wrong_format.cub

echo "\nTesting c_wrong_format_2.cub"
./cub3d ./tests/parser/c_wrong_format_2.cub

echo "\nTesting c_wrong_format_3.cub"
./cub3d ./tests/parser/c_wrong_format_3.cub

echo "\nTesting c_empty_value.cub"
./cub3d ./tests/parser/c_empty_value.cub

echo "\nTesting c_no_c.cub"
./cub3d ./tests/parser/c_no_c.cub
echo ""
