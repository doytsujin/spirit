#include "Spin_System_Chain.h"
#include "Manifoldmath.h"

namespace Data
{
	Spin_System_Chain::Spin_System_Chain(std::vector<std::shared_ptr<Spin_System>> images, std::shared_ptr<Data::Parameters_GNEB> gneb_parameters, bool iteration_allowed) :
		gneb_parameters(gneb_parameters)
	{
		this->noi = images.size();
		this->images = images;
		//this->gneb_parameters = gneb_parameters;

		this->iteration_allowed = iteration_allowed;
		this->idx_active_image = 0;

		this->climbing_image = std::vector<bool>(this->noi, false);
		this->falling_image = std::vector<bool>(this->noi, false);

		this->Rx = std::vector<double>(this->noi, 0);
		this->Rx_interpolated = std::vector<double>((this->noi - 1)*gneb_parameters->n_E_interpolations, 0);
		this->E_interpolated = std::vector<double>((this->noi - 1)*gneb_parameters->n_E_interpolations, 0);
		this->E_array_interpolated = std::vector<std::vector<double>>(7, std::vector<double>((this->noi - 1)*gneb_parameters->n_E_interpolations, 0));

		this->tangents = std::vector<std::vector<double>>(noi, std::vector<double>(3 * this->images[0]->nos));

	}
}