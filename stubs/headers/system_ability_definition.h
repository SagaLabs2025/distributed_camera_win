#ifndef STUBS_SYSTEM_ABILITY_DEFINITION_H
#define STUBS_SYSTEM_ABILITY_DEFINITION_H

// Minimal compatibility header for REGISTER_SYSTEM_ABILITY_* macros used by distributed_camera services.
// In macOS local build we do not register system abilities to a real SA framework.

#define REGISTER_SYSTEM_ABILITY_BY_ID(ClassName, SaId, RunOnCreate)

#endif // STUBS_SYSTEM_ABILITY_DEFINITION_H

