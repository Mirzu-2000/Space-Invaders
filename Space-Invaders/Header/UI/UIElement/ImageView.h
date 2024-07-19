#pragma once

#include "../../Header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;

		public:
			ImageView();
			~ImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			void setTexture(sf::String texture_path);
			void setScale(float width, float height);
			void setPosition(sf::Vector2f position);
			void setRotation(float rotation_angle);

			void setOriginAtCentre();
			void setImageAlpha(float alpha);
			void setCentreAlinged();

		};
	}
}