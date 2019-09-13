dirname = path.dirname(__file__)

tribes:new_ware_type {
   msgctxt = "ware",
   name = "balsa",
   -- TRANSLATORS: This is a ware name used in lists of wares
   descname = pgettext("ware", "Balsa"),
   helptext_script = dirname .. "helptexts.lua",
   icon = dirname .. "menu.png",
   default_target_quantity = {
      amazons = 10,
   },
   preciousness = {
      amazons = 20,
   },

   animations = {
      idle = {
         pictures = path.list_files(dirname .. "idle.png"),
         hotspot = {8, 8},
      },
   }
}
