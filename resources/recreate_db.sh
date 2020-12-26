#!/bin/bash
rm -f uchat.sqlite

sqlite3 rdlog.sqlite < ./sql/message.sql
