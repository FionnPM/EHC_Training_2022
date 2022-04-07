#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'
GR='\033[0;32m'

if [ "$(id -u)" != "0" ]; then
   echo -e $RED"Are you root?"$NC
   exit 1
fi
tar -xvf jdk-14.0.2-bin.tar.gz -C /opt 1>/dev/null 2>>log
cat <<-'EOF' > /etc/profile.d/java.sh
export JAVA_HOME=/opt/jdk-14.0.2
export PATH=$JAVA_HOME/bin:$PATH
EOF

echo -e $GR "Done, logout and login again to load new Java version, to check: java -version"
