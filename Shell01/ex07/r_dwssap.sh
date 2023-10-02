cat /etc/passwd | sed -e '1d ;3~2d' | cut -f1 -d ':' | rev | sort -r | sed -n ''$FT_LINE1','$FT_LINE2'p' | tr '\n' ',' | sed 's/,$/./g' | sed 's/,/, /g'
