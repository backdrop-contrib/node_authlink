# Node Authorize Link

Generates links to view, edit, or delete content without login.

This module maintains authorization keys for every node and gives additional
grants (view/edit/delete) to every user (anonymous too), who accesses a page
with the correct key in the URL.

The module also provides tokens, useful for instance for Rules actions like
notification mails.

Authkeys can get generated for every node (in configured content types) once for
all operations. In each content type form you can configure, which operations to
allow and automatic expiration of the keys.

As soon as authkeys are enabled, a key will automatically get created, whenever
a new node of that type gets created.

## Installation

Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

Configure the content types for you wish to use authorize links and create keys
in a batch on the same form.

To actually display the key, for example to copy-paste, use Views.

Create a node based view on admin/structure/views/add, for example a block.
Add a contextual filter (right column) for the node ID (Content: Nid),
provide a default value: Content ID from URL. Specify validation criteria
(like Basic validation or content type). "Action to take if filter value does not
validate" should be "Hide view".

For fields (left column in views UI) add Content: "Path" (hidden) and "Node Auth link:
Authkey". The full URL gets assemled with some rewrite like
`[path]?authkey=[authkey]`

Set the access to that view as desired, for example set the role that should
be able to see that info, or set it based on permissions.

Save and head over to the Layout admin UI, for example
admin/structure/layouts/manage/default.
Add the newly created views block to the desired region and save.

Both the view and the layout allow for more tweaks, of course. Above example
should show the basics.

The keys are also exposed to Rules. So if you're using that module, you have
access to the key and link URL to display a message or send a mail, for
example a link to view it: `[node:authlink:view-url]`.

## Issues

Bugs and feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/node_authlink/issues).

## Current maintainers

* [Indigoxela](https://github.com/indigoxela)

## Credits

* Original Drupal author: [Honza Pobořil (Bobík)](https://www.drupal.org/u/bob%C3%ADk)
* Current Drupal maintainer [Joël Pittet (joelpittet)](https://www.drupal.org/u/joelpittet)

Ported to Backdrop by Indigoxela

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
