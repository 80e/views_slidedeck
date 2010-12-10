Provides a View style that displays formatted rows inside a jQuery SlideDeck.

Authors:
  Nick Robillard <http://drupal.org/user/176017>

Sponsors:
  80 Elements <http://80elements.com>


Requirements
------------

1. Views - Drupal contrib


Installation
------------

1. Place this module directory in your modules folder (usually sites/all/modules/).

2. Go to "Administer" > "Site Building" > "Modules" and enable the module.

3. Views displays will now offer an additional Style type called "SlideDeck".


Configuration
-------------

1. A default view called "slidedeck" is provided. Go to "Administer" > "Site Building" > "Views" <admin/build/views/edit/slidedeck> to edit the view.

2. There are a couple Style settings: skin chooser & title field selection. Skin chooser is self explanatory. Title field selection lets you choose which views field to use as the SlideDeck's vertical spline content.

3. To add a new skin, drop the skin folder inside of the module "skins" directory. You will now be able to select it in the SlideDeck Style settings. The skin folder needs to follow a specific naming convention - skin name only or prefixed with "slidedeck-skin-". IE: If your skin container selector in skin.css is ".skin-invasion", then your skin folder needs to be named either "invasion" or "slidedeck-skin-invasion".