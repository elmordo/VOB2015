#pragma once

namespace KVZ
{

    class World;

	class IRule
	{
	public:

		IRule();

		virtual ~IRule();

		virtual bool canApply(const World &world) const = 0;

		virtual void apply(World &world) = 0;

	};

}
