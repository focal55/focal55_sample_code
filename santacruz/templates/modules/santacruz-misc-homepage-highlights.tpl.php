<?php
/**
 * @file
 * Template file for the Homepage Highlight Blocks.
 */
?>
<!-- santacruz-misc-homepage-highlights.tpl.php -->
<div class="row">
  <?php if (isset($programs)) : ?>
  <div class="col-xs-12 col-sm-6">
    <table>
      <tr>
        <td class="image"><img src="<?php print base_path() . path_to_theme() . '/images/homepage-highlights-programs.png'; ?>" /></td>
        <td class="text">
          <div class="programs">
            <h2 class="accent"><span class="thin">EFFICIENCY</span><br>PROGRAMS</h2>
            <?php foreach ($programs as $program) : ?>
            <div class="item"><?php print l($program->title, 'node/' . $program->nid); ?></div>
            <?php endforeach; ?>
          </div>
        </td>
      </tr>
    </table>
  </div>
  <?php endif; ?>
  <?php if (isset($resources)) : ?>
    <div class="col-xs-12 col-sm-6">
      <table>
        <tr>
          <td class="text">
            <div class="resources">
              <h2 class="accent"><span class="thin">HELPFUL</span><br>RESOURCES</h2>
              <?php foreach ($resources as $resource) : ?>
                <div class="item"><?php print l(truncate_utf8($resource->title, 42, TRUE, TRUE), 'node/' . $resource->nid); ?></div>
              <?php endforeach; ?>
            </div>
          </td>
          <td class="image"><img src="<?php print base_path() . path_to_theme() . '/images/homepage-highlights-resources.png'; ?>" /></td>
        </tr>
      </table>
    </div>
  <?php endif; ?>
</div>
