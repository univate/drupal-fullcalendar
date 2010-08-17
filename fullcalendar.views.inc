<?php
// $Id$

function fullcalendar_views_plugins() {
  drupal_add_css(drupal_get_path('module', 'fullcalendar') .'/fullcalendar.css');
  drupal_add_js(drupal_get_path('module', 'fullcalendar') .'/fullcalendar.js');
  jquery_ui_add(array('ui.draggable', 'ui.droppable', 'ui.resizable'));

  return array(
    'style' => array(
      'parent' => array(
        'no ui' => TRUE,
        'handler' => 'views_plugin_style',
        'parent' => '',
      ),
      'fullcalenar' => array(
        'title' => t('Full Calendar'),
        'help' => t('Displays elements in a jquery editable calenar.'),
        'handler' => 'fullcalendar_plugin_style',
        'parent' => 'parent',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'theme' => 'fullcalendar_view',
        'even empty' => TRUE,
      ),
    ),
  );
}

