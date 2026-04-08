<?php

$ini = '/usr/local/php/lib/php.ini';

$result = file_put_contents(
    $ini,
    preg_replace([
        '/^;extension=memcached$/m',
        '/^;extension=phpy$/m',
    ], [
        'extension=memcached',
        'extension=phpy',
    ], file_get_contents($ini))
);

if ($result === false) {
    throw new RuntimeException('Error: Unable to write ini file');
}
