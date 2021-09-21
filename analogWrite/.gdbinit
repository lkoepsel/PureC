target extended-remote :3333

define ter
target extended-remote :3333
end

define cll
target extended-remote :3333
load
monitor reset init
end

define mri
monitor reset init
end