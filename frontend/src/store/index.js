import Vue from 'vue'
import Vuex from 'vuex'


Vue.use(Vuex)

const state = {
  account:null,
  amount:0,
  login:false,
  operate:0,
  cards:[]
}

export default new Vuex.Store({
  state
})
