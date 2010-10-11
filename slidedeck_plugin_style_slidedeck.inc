<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item in a slideshow of an ordered or unordered list.
 */
class slidedeck_plugin_style_slidedeck extends views_plugin_style_list {
  // if the view is still using the old variables replace with the new ones.
  function init(&$view, &$display, $options = NULL) {
    // These are required for the view to continue to work.
    $this->view = &$view;
    $this->display = &$display;

    // Overlay incoming options on top of defaults
    $this->unpack_options($this->options, isset($options) ? $options : $display->handler->get_option('style_options'));

    if ($this->uses_row_plugin() && $display->handler->get_option('row_plugin')) {
      $this->row_plugin = $display->handler->get_plugin('row');
    }
  }

  // Set default options
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  // Render the given style.
  function options_form(&$form, &$form_state) {
    $form['slidedeck_mode'] = array(
      '#title' => 'Mode',
      '#type' => 'radios',
      '#description' => t('Choose the SlideDeck mode.'),
      '#default_value' => ($this->options['slidedeck_mode'] ? $this->options['slidedeck_mode'] : 'horizontal'),
      '#options' => array(
        'horizontal' => t('Horizontal'),
        'vertical' => t('Vertical'),
      ),
    );
    $form['slidedeck_skin'] = array(
      '#title' => 'Skin',
      '#type' => 'radios',
      '#description' => t('Choose a skin.'),
      '#default_value' => ($this->options['slidedeck_skin'] ? $this->options['slidedeck_skin'] : 'slidedeck'),
      '#options' => slidedeck_get_available_skins(),
    );
  }
  
}
