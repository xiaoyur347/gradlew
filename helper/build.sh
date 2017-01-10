#!/bin/bash
javac Hash.java
java Hash https://services.gradle.org/distributions/gradle-2.14.1-all.zip
g++ Hash.cpp md5.cpp -o Hash
./Hash https://services.gradle.org/distributions/gradle-2.14.1-all.zip
