# Node Authorize Link

Generates links to view, edit, or delete content without login.

This module maintains authorization key for every node and gives additional
grants (view/edit/delete) to every user (anonymous too) who accesses a page
with correct key in URL.

The module provides function node_authlink_get_url() to generate absolute URLs
to selected operations (e.g. for email notifications).

Authkeys are generated for every node (in configured content types) once for all
operations. In each content type form you can configure, which operations to
allow and automatic expiration of the keys.

## Installation

Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

Configure the content types for you wish to use authorize links and create keys
in a batch on the same form.

## Issues

Bugs and feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/node_authlink/issues).

## Current maintainers

* Indigoxela (https://github.com/indigoxela)

## Credits

* Original Drupal author: [Honza Pobořil (Bobík)](https://www.drupal.org/u/bob%C3%ADk)
* Current Drupal maintainer [Joël Pittet (joelpittet)](https://www.drupal.org/u/joelpittet)

Ported to Backdrop by Indigoxela

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
