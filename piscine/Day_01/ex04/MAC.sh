ifconfig -a | grep "^. *eth" | sed "s/^.*ether *//" | tr -d ' '
