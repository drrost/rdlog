#!/bin/bash
rm -f uchat.sqlite

sqlite3 uchat.sqlite < ./sql/message.sql
