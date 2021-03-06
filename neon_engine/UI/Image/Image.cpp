//  Created by Theo Penavaire on 06/06/2018
//  Last Update on 06/07/2018 

#include "Image.h"
#include "SDL_image.h"

namespace neon_engine
{

	Image::Image(RendererSptr& renderer, 
		const std::string& file, 
		Vector4<int>& coord, 
		bool isEnabled) :
			AGObject(coord, isEnabled),
			_file(file)
	{
		SDL_Surface	*surface;
		if (!(surface = IMG_Load(file.c_str()))) {
			throw NeonException("Can't create a texture for image: " + file + ". " + SDL_GetError());
		}

		_coord.size.w(surface->w);
		_coord.size.h(surface->h);
		_texture = TextureSptr(SDL_CreateTextureFromSurface(renderer.get(), surface));
		if (!_texture) {
			throw NeonException("Can't create a texture for image: " + file + ". " + SDL_GetError());
		}
	}

	bool Image::operator==(const Image& other) const
	{
		return _file == other._file 
			&& getSize() == other.getSize() 
			&& getPos() == other.getPos();
	}

	void Image::draw(RendererSptr& renderer)
	{
		if (_isEnabled) {
			SDL_Rect	dest = {
				_coord.pos.x(), 
				_coord.pos.y(), 
				_coord.size.w(), 
				_coord.size.h()
			};

			SDL_RenderCopy(renderer.get(), _texture.get(), nullptr, &dest);
		}
	}

	void Image::update(NEvent& event)
	{
	}

}
