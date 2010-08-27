<div class="external-events">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <div class="external-event <?php print $classes[$id]; ?>"><?php print $row; ?></div>
  <?php endforeach; ?>
</div>
<div id="fullcalendar_<?php print $id; ?>" class="fullcalendar"></div>
