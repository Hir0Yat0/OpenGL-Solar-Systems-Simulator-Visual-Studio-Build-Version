#ifndef DEBUGLEVEL_HPP
#define DEBUGLEVEL_HPP

namespace DebugLevel {

enum DebugLevel {
    NONE,
    LOGGING_ERR,
    LOGGING_EXCP,
    LOGGING,
    ALL,
};

constexpr int DBGLVL = LOGGING_ERR;

} // namespace DebugLevel

#endif // DEBUGLEVEL_HPP
