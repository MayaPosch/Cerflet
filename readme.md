# Cerflet #

The Cerflet project provides an easy way to map HTTP requests to handlers, all using standards-compliant, portable C++. It is based around the POCO C++ libraries project.

## Features ##

- Stand-alone HTTP (1.0/1.1) server.
- Threadpool-based workers.
- Easy mapping of URIs to custom classes.

## Example ##

See the 'Hello World' example in the 'sample' folder for a basic implementation of a HTTP Cerflet.

## See also ##

Read this blog post introducing Cerflet for more information and benchmarks of the Hello World example: [https://mayaposch.wordpress.com/2016/05/19/cerflet-like-servlets-but-with-more-c/](https://mayaposch.wordpress.com/2016/05/19/cerflet-like-servlets-but-with-more-c/)

## Requirements ##

In order to build projects with Cerflet the only requirement is to have the POCO C++ libraries and headers installed. For Linux/BSD/OS X and MSYS2 use a package manager, or install from source.

## License ##

The Cerflet license at this point is the same Boost Software License 1.0 as used by the POCO C++ libraries.