#!/bin/bash
rm -f rdlog.sqlite

sqlite3 rdlog.sqlite < ./sql/message.sql
