ldapsearch -LLL -Q "(uid=z*)" cn | grep 'cn:' | sed 's/cn: *//' | sort -r -f
