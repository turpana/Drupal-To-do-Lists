<?php
/**
 * @file todo-lists.tpl.php
 * Todo_lists template
 *
 * Variables
 * - $lists: array of lists rendered as link to to-do list page
 */
?>
<div class="todo-lists">
<?php if (!empty($lists)): ?>
  <ul>
  <?php foreach ($lists as $list): ?>
    <li><?php print $list ?></li>
  <?php endforeach; ?> 
  </ul>
<?php else: ?>
  <p>No to-do lists found.</p>
<?php endif; ?>
</div>
