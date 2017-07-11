<?php
/**
 * @file
 * Helper.
 */


/**
 * Helper function to find and render a block.
 */
function v_render_block_content($module, $delta) {
  $output = '';
  if ($block = block_load($module, $delta)) {
    if ($build = module_invoke($module, 'block_view', $delta)) {
      $delta = str_replace('-', '_', $delta);
      drupal_alter(array(
        'block_view',
        "block_view_{$module}_{$delta}"
      ), $build, $block);

      if (!empty($build['content'])) {
        return is_array($build['content']) ? render($build['content']) : $build['content'];
      }
    }
  }
  return $output;
}

/**
 * Helper function to find and render a block as block.
 */
function v_render_block($module, $delta) {
  $_block = block_load($module, $delta);
  $_render_array = _block_get_renderable_array(_block_render_blocks(array($_block)));
  $_output = drupal_render($_render_array);
  return $_output;
}
