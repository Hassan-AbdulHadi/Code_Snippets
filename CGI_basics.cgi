#!C:\Users\AG\AppData\Local\Programs\Python\Python37\python.exe
#interpreter's path , must be in the first line 
import sys
import os

#headers must be at the beginning of the script,each header ends with \n, the last one should end with \n\n
sys.stdout.write("Content-type: text/html\n\n") #this header is mandatory
#sys.stdout.write("Location: https://www.youtube.com\n\n")

post =sys.stdin.read(10) # post data will be received through stdin buffer

en = os.environ #environment variables 
#All request's HTTP headers will be written in environment variables, prefixed with "HTTP_"
#you can obtain cookies through the variable HTTP_COOKIE
#and query strings thruogh the variable QUERY_STRING
for i in en:
    sys.stdout.write(i+" : "+en[i]+"<br>")

#Example
'''
HTTP_HOST : localhost
HTTP_CONNECTION : keep-alive
HTTP_CACHE_CONTROL : max-age=0
HTTP_UPGRADE_INSECURE_REQUESTS : 1
HTTP_USER_AGENT : Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.87 Safari/537.36
HTTP_SEC_FETCH_DEST : document
HTTP_ACCEPT : text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
HTTP_SEC_FETCH_SITE : none
HTTP_SEC_FETCH_MODE : navigate
HTTP_SEC_FETCH_USER : ?1
HTTP_ACCEPT_ENCODING : gzip, deflate, br
HTTP_ACCEPT_LANGUAGE : en-US,en;q=0.9
HTTP_COOKIE : hello:from Cookies
PATH : 
SYSTEMROOT : C:\Windows
COMSPEC : C:\Windows\system32\cmd.exe
PATHEXT : .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC
WINDIR : C:\Windows
SERVER_SIGNATURE :
Apache/2.4.27 (Win64) PHP/7.4.2 Server at localhost Port 80

SERVER_SOFTWARE : Apache/2.4.27 (Win64) PHP/7.4.2
SERVER_NAME : localhost
SERVER_ADDR : ::1
SERVER_PORT : 80
REMOTE_ADDR : ::1
DOCUMENT_ROOT : C:/wamp64/www
REQUEST_SCHEME : http
CONTEXT_PREFIX : /cgi-bin/
CONTEXT_DOCUMENT_ROOT : c:/wamp64/cgi-bin/
SERVER_ADMIN : wampserver@wampserver.invalid
SCRIPT_FILENAME : C:/wamp64/cgi-bin/CGI.py
REMOTE_PORT : 50091
GATEWAY_INTERFACE : CGI/1.1
SERVER_PROTOCOL : HTTP/1.1
REQUEST_METHOD : GET
QUERY_STRING : q=hi
REQUEST_URI : /cgi-bin/CGI.py?q=hi
SCRIPT_NAME : /cgi-bin/CGI.py
'''
