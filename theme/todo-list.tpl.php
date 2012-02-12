<?php
/**
 * @file todo-list.tpl.php
 * Todo list template
 *
 * Variables
 * - $todo_items: array of to-do items rendered as title and link to mark deleted
 */
?>
<div class="todo-list">
<?php if ( !empty($items) ): ?>
  <ul>
  <?php foreach ($items as $item): ?>
    <li><?php print $item; ?></li>
  <?php endforeach; ?>
  </ul>
<?php else: ?>
  <p>No to-do items found.</p>
<?php endif; ?>
</div>
