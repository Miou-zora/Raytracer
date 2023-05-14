/*
** EPITECH PROJECT, 2023
** Raytracer [WSL : Ubuntu]
** File description:
** SFMLDisplayer
*/

#include "SFMLDisplayer.hpp"

void RayTracer::SFMLDisplayer::display(const RayTracer::Frame &frame)
{
    sf::Image image;
    sf::Color color;

    image.create(frame.getWidth(), frame.getHeight());
    for (size_t i = 0; i < frame.getHeight(); i++) {
        for (size_t j = 0; j < frame.getWidth(); j++) {
            color = sf::Color(frame.getPixel(std::pair<size_t, size_t>(j, i)).getRed(),
                            frame.getPixel(std::pair<size_t, size_t>(j, i)).getGreen(),
                            frame.getPixel(std::pair<size_t, size_t>(j, i)).getBlue());
            image.setPixel(j, frame.getHeight() - i - 1, color);
        }
    }
    sf::Texture texture;
    texture.create(frame.getWidth(), frame.getHeight());
    texture.update(image);
    sf::Sprite sprite(texture);
    m_window.clear(sf::Color::Black);
    m_window.draw(sprite);
    m_window.display();
}
