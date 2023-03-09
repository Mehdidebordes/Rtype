#!/usr/bin/env bash

echo Welcome to
cat << EOF
__________        ________________.___._____________________
\______   \       \__    ___/\__  |   |\______   \_   _____/
 |       _/  ______ |    |    /   |   | |     ___/|    __)_
 |    |   \ /_____/ |    |    \____   | |    |    |        \\
 |____|_  /         |____|    / ______| |____|   /_______  /
        \/                    \/                         \/
EOF

rm -f server client
cmake .
cmake --build .
fuser -k 1042/udp; fuser -k 3000/udp
# ./server & ./client 3000 && kill $!
