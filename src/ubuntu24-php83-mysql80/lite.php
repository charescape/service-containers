<?php

if (str_contains($_SERVER['GIT_MSG'] ?? '', ' --lite')) {
    $dockerfile = file_get_contents(__DIR__ . '/Dockerfile');

    $dockerfile = preg_replace(
        [
            '#^imagemagick #m',
            '#^libvips42t64 #m',
            '#^libvips-dev #m',
            '#^nodejs #m',
            '#^npm #m',
        ],
        ' ',
        $dockerfile
    );

    var_dump($dockerfile);

    file_put_contents(__DIR__ . '/Dockerfile', $dockerfile, LOCK_EX);
}
