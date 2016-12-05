/*
 * Copyright (C) 2006-2015 by the Widelands Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef WL_GRAPHIC_GL_BLIT_PROGRAM_H
#define WL_GRAPHIC_GL_BLIT_PROGRAM_H

#include <memory>
#include <vector>

#include "base/macros.h"
#include "base/rect.h"
#include "graphic/blend_mode.h"
#include "graphic/blit_mode.h"
#include "graphic/color.h"
#include "graphic/gl/blit_data.h"
#include "graphic/gl/system_headers.h"
#include "graphic/gl/utils.h"

// Blits images. Can blend them with player color or make them monochrome.
class BlitProgram {
public:
	struct Arguments {
		Rectf destination_rect;
		float z_value;
		BlitData texture;
		BlitData mask;
		RGBAColor blend;
		BlendMode blend_mode;
		BlitMode blit_mode;
	};

	// Returns the (singleton) instance of this class.
	static BlitProgram& instance();
	virtual ~BlitProgram();

	// Draws the rectangle 'gl_src_rect' from the texture with the name
	// 'gl_texture_image' to 'gl_dest_rect' in the currently bound framebuffer. All
	// coordinates are in the OpenGL frame. The 'texture_mask' is used to selectively apply
	// the 'blend'. This is used for blitting player colored images.
	void draw(const Rectf& gl_dest_rect,
	          const float z_value,
	          const BlitData& texture,
	          const BlitData& mask,
	          const RGBAColor& blend,
	          const BlendMode& blend_mode);

	// Draws the rectangle 'gl_src_rect' from the texture with the name
	// 'texture' to 'gl_dest_rect' in the currently bound framebuffer. All
	// coordinates are in the OpenGL frame. The image is first converted to
	// luminance, then all values are multiplied with blend.
	void draw_monochrome(const Rectf& gl_dest_rect,
	                     const float z_value,
	                     const BlitData& blit_source,
	                     const RGBAColor& blend);

	// Draws a bunch of items at once.
	virtual void draw(const std::vector<Arguments>& arguments) = 0;

protected:
	BlitProgram();

private:
	DISALLOW_COPY_AND_ASSIGN(BlitProgram);
};

#endif  // end of include guard: WL_GRAPHIC_GL_BLIT_PROGRAM_H
