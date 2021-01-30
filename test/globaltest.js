'use strict';

const buildType = process.config.target_defaults.default_configuration;
const assert = require('assert');

test(require(`./build/${buildType}/binding.node`));
test(require(`./build/${buildType}/binding_noexcept.node`));

function test(binding) {
  const {
    AddPropertyAndGetFromGlobal,
    GetGlobalVariableByKey
  } = binding.globaltest;

  const testValue = "test-value";
  assert.strictEqual(AddPropertyAndGetFromGlobal("the-key", testValue), testValue);


  global.globalVariable = "global-variable";
  assert.strictEqual(GetGlobalVariableByKey("globalVariable"), globalVariable);
}

