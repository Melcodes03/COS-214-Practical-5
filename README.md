# CampusGuard

**COS 214 Practical 5** — an emergency-response coordination platform for a
university campus, demonstrating Command, Mediator, Adapter, Facade,
Composite and State working together as one coherent system.

An incident (e.g. a fire alarm) is reported and moves through a lifecycle
(`Reported → Dispatched → Resolved`). A single `EmergencyFacade` call
coordinates dispatching a `SecurityUnit` and `MedicUnit` (Command), securing
a `CampusArea`/`CampusUnit` (Composite), and raising a campus-wide alert.
Response units coordinate with each other only through an
`IncidentCoordinator` (Mediator), never directly. Physical door hardware is
integrated through a `LegacyDoorAccess` adapter wrapping a `DoorController`
that was never designed for this system (Adapter). Each `CampusUnit` also
tracks its own lock lifecycle (`Unlocked → Locked → Evacuation`) as a
separate State hierarchy (`ZoneState`).

## Team & File Ownership

| Person | Owns |
|---|---|
| Robert | Composite (`CampusComponent`, `CampusArea`, `CampusUnit`), Command (`CampusCommand` + concrete commands), `Makefile`, `Dockerfile`, `docker-compose.yml` |
| Chelsy | Mediator (`IncidentCoordinator`, `ResponseUnit`, `ResponseHub`, `SecurityUnit`, `MedicUnit`, `FacilitiesUnit`, `AlertService`), Adapter (`AccessPoint`, `DoorController`, `LegacyDoorAccess`), `main.cpp` |
| Melaney | State hierarchy (`IncidentState` + concrete states, `Incident`), `ZoneState` hierarchy (`UnlockedState`, `LockedState`, `EvacuationState`), Facade (`EmergencyFacade`) |

If you don't own a file, discuss changes with its owner first.

## Requirements

Everything below can be run either directly on a machine with `g++`
(C++11), `make`, `gdb` and `valgrind` installed, **or** inside the provided
Docker image with no host dependencies at all (see [Docker](#docker)).

## Build

```
make
```

Compiles with `-std=c++11 -Wall -g` and produces the `CampusGuard`
executable. To rebuild from scratch:

```
make clean
make
```

## Run

```
./CampusGuard
```

Runs the full demo: two end-to-end scenarios (a fire alarm in the
Engineering Building, and a suspicious-activity response in Residence
Block C) showing Facade, Command, Mediator, Composite, Adapter and State
collaborating, followed by a third scenario exercising remaining state
transitions, unlock procedures, coordinator branches and a handled
invalid-operation case (a command dispatched to a null destination).

## Debugging with GDB

Example session, breaking on `CampusUnit::secure` to inspect the zone
state before and after a secure attempt:

```
gdb ./CampusGuard

(gdb) break CampusUnit::secure
(gdb) run
(gdb) print this->state->getStatusName()
(gdb) next
(gdb) continue
```

Use `bt` for a backtrace and `print *this` inside any method to inspect
the current object's state.

## Valgrind

```
make valgrind
```

Equivalent to:

```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./CampusGuard
```

---

# Running with Docker

## Prerequisites

Make sure Docker is installed and running on your system.

## Build and run

From the root of the project, where the `Dockerfile` and
`docker-compose.yml` are located:

```
docker compose up --build
```

This builds the image, compiles the application using the project's
Makefile, and runs `CampusGuard` inside the container.

## Rebuild after making changes

If you make changes to the C++ source code, rebuild before running again:

```
docker compose up --build
```

## Using the Makefile directly (without Docker)

```
make
./CampusGuard
```

```
make valgrind
```

```
gdb ./CampusGuard
```

To clean the generated build files:

```
make clean
```