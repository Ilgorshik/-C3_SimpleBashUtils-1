echo "gcc Makefile:"; ./s21_grep gcc Makefile > s21_grep.log; grep gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-e gcc -e count Makefile:"; ./s21_grep -e gcc -e count Makefile > s21_grep.log; grep -e gcc -e count Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-i gcc Makefile:"; ./s21_grep -i gcc Makefile > s21_grep.log; grep -i gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-v gcc Makefile:"; ./s21_grep -v gcc Makefile > s21_grep.log; grep -v gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-c gcc Makefile:"; ./s21_grep -c gcc Makefile > s21_grep.log; grep -c gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-l gcc Makefile:"; ./s21_grep -l gcc Makefile > s21_grep.log; grep -l gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-n gcc Makefile:"; ./s21_grep -n gcc Makefile > s21_grep.log; grep -n gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-h gcc Makefile:"; ./s21_grep -h gcc Makefile > s21_grep.log; grep -h gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-s gcc nofile.txt:"; ./s21_grep -s gcc nofile.txt > s21_grep.log; grep -s gcc nofile.txt > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-f Makefile Makefile:"; ./s21_grep -f Makefile Makefile > s21_grep.log; grep -f Makefile Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "-o gc Makefile:"; ./s21_grep -o gc Makefile > s21_grep.log; grep -o gc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -iv Makefile:"; ./s21_grep -iv gcc Makefile > s21_grep.log; grep -iv gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -in Makefile:"; ./s21_grep -in gcc Makefile > s21_grep.log; grep -in gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -hl Makefile:"; ./s21_grep -hl gcc Makefile > s21_grep.log; grep -hl gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -is nofile.txt:"; ./s21_grep -is gcc nofile.txt > s21_grep.log; grep -is gcc nofile.txt > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -e gcc -e count -v Makefile:"; ./s21_grep -e gcc -e count -v Makefile > s21_grep.log; grep -e gcc -e count -v Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -nl Makefile:"; ./s21_grep gcc -nl Makefile > s21_grep.log; grep gcc -nl Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -e gcc -f Makefile Makefile:"; ./s21_grep -e gcc -f Makefile Makefile > s21_grep.log; grep -e gcc -f Makefile Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -ov Makefile:"; ./s21_grep -ov gcc Makefile > s21_grep.log; grep -ov gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -oi Makefile:"; ./s21_grep -oi gcc Makefile > s21_grep.log; grep -oi gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -ic Makefile:"; ./s21_grep -ic gcc Makefile > s21_grep.log; grep -ic gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -ih Makefile:"; ./s21_grep -ih gcc Makefile > s21_grep.log; grep -ih gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -on Makefile:"; ./s21_grep -on gcc Makefile > s21_grep.log; grep -on gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -il Makefile:"; ./s21_grep -il gcc Makefile > s21_grep.log; grep -il gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log
echo "gcc -vn Makefile:"; ./s21_grep -vn gcc Makefile > s21_grep.log; grep -vn gcc Makefile > grep.log; diff -s s21_grep.log grep.log; rm grep.log; rm s21_grep.log