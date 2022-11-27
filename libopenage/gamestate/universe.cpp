// Copyright 2022-2022 the openage authors. See copying.md for legal info.

#include "universe.h"

#include "gamestate/terrain.h"

// ASDF: testing
#include "renderer/entity_factory.h"

namespace openage::gamestate {

Universe::Universe(const util::Path &root_dir) :
	world{} {
	// ASDF: testing
	auto texpath = root_dir / "assets" / "textures" / "test_terrain_tex.png";
	this->terrain = std::make_shared<Terrain>(texpath);
}

std::shared_ptr<World> Universe::get_world() {
	return this->world;
}

std::shared_ptr<Terrain> Universe::get_terrain() {
	return this->terrain;
}

void Universe::attach_renderer(const std::shared_ptr<renderer::RenderFactory> &render_factory) {
	this->render_factory = render_factory;

	// ASDF: testing
	auto terrain_render_entity = this->render_factory->add_terrain_render_entity();
	this->terrain->set_render_entity(terrain_render_entity);
}

} // namespace openage::gamestate
