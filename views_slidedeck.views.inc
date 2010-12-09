<?php

/**
 * Implements hook_views_plugins().
 */
function views_slidedeck_views_plugins() {
  return array(
    'style' => array(
      'views_slidedeck' => array(
        'title' => t('SlideDeck'),
        'help' => t('Display the results as a SlideDeck.'),
        'handler' => 'views_slidedeck_plugin_style_slidedeck',
        'theme' => 'views_slidedeck',
        'uses options' => TRUE,
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'type' => 'normal',
        'parent' => 'list',
      ),
    ),
  );
}
