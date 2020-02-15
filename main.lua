camera = {x = 0, y = 0, s = 50}
sprites = {}
black = {}
white = {}
active_player = "white"
state = {}

map = {width = 64, height = 64}

function setRoom(room)
  for x = room.x, room.x + room.w - 1 do
    for y = room.y, room.y + room.h - 1 do
      map.data[x][y] = " "
    end
  end
end

function generateMap()
  map.data = {}
  center = {x = math.floor(map.width / 2), y = math.floor(map.height / 2)}
  for x = 0, map.width do
    map.data[x] = {}
    for y = 0, map.height do
      map.data[x][y] = ""
    end
  end
  rooms = {}
  rooms[0] = {
    x = center.x - 3,
    y = 0,
    w = 6,
    h = 6,
    connection = 4,
    connections = {false, true, true, true}
  }
  rooms[1] = {
    x = center.x - 3,
    y = map.height - 6,
    w = 6,
    h = 6,
    connection = 4,
    connections = {false, true, true, true}
  }
  setRoom(rooms[0])
  setRoom(rooms[1])
end

function drawSprite(sprite, x, y)
  love.graphics.setColor(1, 1, 1)
  love.graphics.draw(
    sprite,
    camera.s * (x - camera.x),
    camera.s * (y - camera.y),
    0,
    camera.s / sprite:getWidth(),
    camera.s / sprite:getHeight()
  )
end
function drawTile(x, y, color_light, color_dark)
  if (x % 2) ~= (y % 2) then
    if color_dark == nil then
      love.graphics.setColor(0.71, 0.533, 0.388)
    else
      love.graphics.setColor(color_dark)
    end
  else
    if color_light == nil then
      love.graphics.setColor(0.941, 0.851, 0.71)
    else
      love.graphics.setColor(color_light)
    end
  end
  love.graphics.rectangle(
    "fill",
    camera.s * (x - camera.x),
    camera.s * (y - camera.y),
    camera.s,
    camera.s
  )
end

function drawMap()
  for x = 0, map.width do
    for y = 0, map.height do
      if map.data[x][y] ~= "" then
        drawTile(x, y)
      end
    end
  end
end

-- function drawSprite(sprite, x, y)
--   love.graphics.setColor(1, 1, 1)
--   love.graphics.draw(
--     sprite,
--     camera.s * x - camera.x,
--     camera.s * y - camera.y,
--     0,
--     camera.s / sprite:getWidth(),
--     camera.s / sprite:getHeight()
--   )
-- end
-- function drawTile(x, y, color_light, color_dark)
--   if (x % 2) ~= (y % 2) then
--     if color_dark == nil then
--       love.graphics.setColor(0.71, 0.533, 0.388)
--     else
--       love.graphics.setColor(color_dark)
--     end
--   else
--     if color_light == nil then
--       love.graphics.setColor(0.941, 0.851, 0.71)
--     else
--       love.graphics.setColor(color_light)
--     end
--   end
--   love.graphics.rectangle(
--     "fill",
--     camera.s * x - camera.x,
--     camera.s * y - camera.y,
--     camera.s,
--     camera.s
--   )
-- end
--
-- function drawGrid()
--   for x = 0, 8 do
--     for y = 0, 8 do
--       drawTile(x, y)
--     end
--   end
-- end
-- function drawPieces()
--   for k, piece in pairs(black) do
--     drawSprite(piece.sprite, piece.x, piece.y)
--   end
--   for k, piece in pairs(white) do
--     drawSprite(piece.sprite, piece.x, piece.y)
--   end
-- end

function love.load()
  sprites.white = {}
  sprites.black = {}
  sprites.white.king = love.graphics.newImage("resources/wK.png")
  sprites.white.queen = love.graphics.newImage("resources/wQ.png")
  sprites.white.bishop = love.graphics.newImage("resources/wB.png")
  sprites.white.knight = love.graphics.newImage("resources/wN.png")
  sprites.white.rook = love.graphics.newImage("resources/wR.png")
  sprites.white.pawn = love.graphics.newImage("resources/wP.png")
  sprites.black.king = love.graphics.newImage("resources/bK.png")
  sprites.black.queen = love.graphics.newImage("resources/bQ.png")
  sprites.black.bishop = love.graphics.newImage("resources/bB.png")
  sprites.black.knight = love.graphics.newImage("resources/bN.png")
  sprites.black.rook = love.graphics.newImage("resources/bR.png")
  sprites.black.pawn = love.graphics.newImage("resources/bP.png")

  generateMap()
end

-- function love.mousereleased(x, y, button, istouch, presses)
--   if button ~= 1 then
--     return
--   end
--   print(x, y)
--   state.x = math.floor((x + camera.x) / camera.s)
--   state.y = math.floor((y + camera.y) / camera.s)
--   state.valid = {
--     {x = state.x + 1, y = state.y},
--     {x = state.x - 1, y = state.y},
--     {x = state.x, y = state.y + 1},
--     {x = state.x, y = state.y - 1}
--   }
--   print(state.x, state.y)
-- end
--
function love.update(dt)
  if love.keyboard.isDown("up") or love.keyboard.isDown("w") then
    camera.y = camera.y - 0.1
  end
  if love.keyboard.isDown("down") or love.keyboard.isDown("s") then
    camera.y = camera.y + 0.1
  end
  if love.keyboard.isDown("left") or love.keyboard.isDown("a") then
    camera.x = camera.x - 0.1
  end
  if love.keyboard.isDown("right") or love.keyboard.isDown("d") then
    camera.x = camera.x + 0.1
  end
  if love.keyboard.isDown("q") and camera.s < 100 then
    camera.s = camera.s + 1
  end
  if love.keyboard.isDown("e") and camera.s > 10 then
    camera.s = camera.s - 1
  end
  if love.keyboard.isDown("escape") then
    love.event.quit()
  end
end
function love.draw()
  drawMap()
  -- if state.x ~= nil and state.y ~= nil then
  --   drawTile(state.x, state.y, {0.505, 0.780, 0.521}, {0.219, 0.556, 0.235})
  --   for i, move in pairs(state.valid) do
  --     drawTile(move.x, move.y, {1.0, 0.945, 0.462}, {0.984, 0.752, 0.176})
  --   end
  -- end
  -- drawPieces()
end
