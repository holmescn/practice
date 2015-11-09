local lu = require 'luaunit'

lu.test("Basic test.", function()

end)

--[[

lu.test("Description", function()

end, { setUp = function() end })

lu.test("Description", function()

end, { setUp = function() end, tearDown = function() end})


local suite = {}

suite.setUp = function()
end

suite.tearDown = function()
end

suite.basicTest1 = function()
end

suite.basicTest = {
    description = "",
    func = function()
    end
}

lu.run(suite)
]]

lu.run()
