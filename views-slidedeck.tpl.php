<?php

/**
 * @file
 * Default views template for displaying a SlideDeck.
 *
 * - $view: The View object.
 * - $options: Settings for the active style.
 * - $rows: The rows output from the View.
 * - $title: The title of this group of rows. May be empty.
 * - $attributes: The containing div's attributes string.
 * - $rendered_rows: An array of row titles and content.
 *
 * @ingroup views_templates
 */
?>

<div<?php print $attributes ?>>
<dl class="slidedeck">
  <?php foreach ($rendered_rows as $row) { ?>
  <dt><?php print $row->title ?></dt>
  <dd><?php print $row->content ?></dd>
  <?php } ?>
</dl>
</div>
