<?php
// $Id$

class fullcalendar_plugin_style extends views_plugin_style {

 /**
   * Init will be called after construct, when the plugin is attached to a
   * view and a display. 
   */
  function init(&$view, &$display) {
    parent::init($view, $display);
    $this->view->pager['items_per_page'] = 0;
  }

  function options(&$options) {
    parent::options($options);
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    //dsm($this->view);
    $display = $this->view->current_display;
    $fields = $this->view->display[$display]->display_options['fields'];
    if (empty($fields)) {
      $fields = $this->view->display['default']->display_options['fields'];
    }
    $date_options = array();
    foreach($fields as $field => $name) {
      $date_options[$field] = $name['label'];
    }
    $form['from_date_field'] = array(
      '#type' => 'select',
      '#title' => t('From date field'),
      '#description' => t('This plugin expects a date cck field with a to and from field.'),
      '#options' => $date_options,
    );
    $form['to_date_field'] = array(
      '#type' => 'select',
      '#title' => t('To date field'),
      '#description' => t('This plugin expects a date cck field with a to and from field.'),
      '#options' => $date_options,
    );
    //dsm($this->view);
  }

  function options_validate(&$form, &$form_state) {
    
  }

  function options_submit(&$form, &$form_state) {
    
  }

/*
  function render() {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    // Render each group separately and concatenate.  Plugins may override this
    // method if they wish some other way of handling grouping.
    $output = '';
    foreach ($sets as $title => $records) {
      if ($this->uses_row_plugin()) {
        $rows = array();
        foreach ($records as $row_index => $row) {
          $this->view->row_index = $row_index;
          $rows[] = $this->row_plugin->render($row);
        }
      }
      else {
        $rows = $records;
      }

      $output .= theme($this->theme_functions(), $this->view, $this->options, $rows, $title);
    }
    unset($this->view->row_index);
    //return $output;

    // We build the groups here to pass them to the node_selector function through the form.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);
    $this->sets = $sets;

    // Append suffix to avoid clashing between multiple VBOs on same page.
    static $form_suffix;
    if (isset($form_suffix)) {
      $form_suffix++;
    }
    else {
      $form_suffix = 1;
    }
    return $output;
  }
*/
  private function populate_operations(&$options) {
  
  }

  function strip_view() {
    $this->view->pager_original = $this->view->pager;
    $this->view->set_use_pager(FALSE);
    $this->view->exposed_widgets = NULL;
    $this->view->display_handler->set_option('header', '');
    $this->view->display_handler->set_option('footer', '');
    $this->view->display_handler->set_option('use_pager', FALSE);
    $this->view->attachment_before = '';
    $this->view->attachment_after = '';
    $this->view->feed_icon = NULL;
  }
}

