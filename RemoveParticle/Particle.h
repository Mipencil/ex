class Tessellator;
class Particle{
	public:
		void render(Tessellator &,float,float,float,float,float,float);
};
class BreakingItemParticle{
	public:
		void render(Tessellator &,float,float,float,float,float,float);
};
class TerrainParticle{
	public:
		void render(Tessellator &,float,float,float,float,float,float);
};
class FlameParticle:public Particle{};
class LavaParticle:public Particle{};
class RedDustParticle:public Particle{};
class CritParticle:public Particle{};
class HugeExplosionParticle:public Particle{};
class FallingDustParticle:public Particle{};
class SmokeParticle:public Particle{};
class InkParticle:public Particle{};
class HugeExplosionSeedParticle:public Particle{};
class EnchantingTableParticle:public Particle{};
class HeartParticle:public Particle{};
class PortalParticle:public Particle{};
class MobFlameParticle:public Particle{};
class SplashParticle:public Particle{};
class RainSplashParticle:public Particle{};
class WaterWakeParticle:public Particle{};
class SuspendedTown:public Particle{};
class SpellParticle:public Particle{};
class BubbleParticle:public Particle{};
class DripParticle:public Particle{};
class WaterDropParticle:public Particle{};
class ExplodeParticle:public Particle{};