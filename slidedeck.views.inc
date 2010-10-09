<?php

/**
 * @file
 * Defines the View Style Plugins for Views Slideshow module.
 */

/**
 * Implements hook_views_plugins().
 */
function slidedeck_views_plugins() {
  return array(
    'style' => array(
      'slidedeck' => array(
        'title' => t('SlideDeck'),
        'help' => t('Display the results as a SlideDeck.'),
        'handler' => 'slidedeck_plugin_style_slidedeck',
        'theme' => 'slidedeck',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'type' => 'normal',
        'parent' => 'list',
      ),
    ),
  );
}
