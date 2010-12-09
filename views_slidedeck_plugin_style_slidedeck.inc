<?php

/**
 * Style plugin to render each item of a SlideDeck and to handle the options form.
 */
class views_slidedeck_plugin_style_slidedeck extends views_plugin_style_list {
  // If the view is still using the old variables replace with the new ones.
  function init(&$view, &$display, $options = NULL) {
    // These are required for the view to continue to work.
    $this->view = &$view;
    $this->display = &$display;

    // Overlay incoming options on top of defaults.
    $this->unpack_options($this->options, isset($options) ? $options : $display->handler->get_option('style_options'));

    if ($this->uses_row_plugin() && $display->handler->get_option('row_plugin')) {
      $this->row_plugin = $display->handler->get_plugin('row');
    }
  }

  // Set default options.
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  // Render the given style.
  function options_form(&$form, &$form_state) {
    $skin_options = array();
    foreach (views_slidedeck_get_available_skins() as $skin_id => $skin) {
      $name = $skin['meta']['Skin Name'];
      if (!$name) {
        $name = drupal_ucfirst($skin_id);
      }
      $skin_options[$skin_id] = $name;
    }
    $form['slidedeck_skin'] = array(
      '#title' => 'Skin',
      '#type' => 'radios',
      '#description' => t('Choose a skin.'),
      '#default_value' => ($this->options['slidedeck_skin'] ? $this->options['slidedeck_skin'] : 'slidedeck'),
      '#options' => $skin_options,
    );
    $fields = $this->view->display[$this->view->current_display]->display_options['fields'];
    if (!$fields) {
      $fields = $this->view->display['default']->display_options['fields'];
    }
    $form['slidedeck_title_field'] = array(
      '#title' => 'Which field do you want to use as your title?',
      '#type' => 'radios',
      '#description' => t("This is the content that will be used as each SlideDeck panel's title."),
      '#default_value' => ($this->options['slidedeck_title_field'] ? $this->options['slidedeck_title_field'] : 'none'),
      '#options' => array('none' => '(none)') + drupal_map_assoc(array_keys($fields)),
    );
  }
  
}
