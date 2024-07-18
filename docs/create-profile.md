# How to create a macro profile for blackpkb

Create a profile for blackpkb is super easy, even for non-programmer. You just need
to edit source files, recompile and it's done. Here are some steps I recommend:

 1. goto /firmware/blackpkb/Core/Inc/profile.h.
 2. add an entry in the **matrix_profile_t** enumeration. Make sure to add a comma in the last entry before adding new one.
 3. goto /firmware/blackpkb/Core/Src/profile.c. You should see 2 already created profiles based on my need. Add your custom profile in **profileList** array, before the blank **{}**. Make sure to add a comma like the previous entries.
 4. Keycodes are defined in keycode.h. Check it out if needed.
 5. The profiles can be selected by pressing the built in button of the rotary encoder. The first profile selected always is the top one, so if you want to use your custom profile first, place it on top of **profileList**.